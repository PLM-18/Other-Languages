// Required modules
const express = require('express');
const fs = require('fs');
const xml2js = require('xml2js');
const bodyParser = require('body-parser');
const path = require('path');

const app = express();
const PORT = process.env.PORT || 3000;

// Middleware
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

// XML file path
const XML_FILE_PATH = path.join(__dirname, 'database.xml');

// Utility functions to read and write XML
const readXMLFile = () => {
  return new Promise((resolve, reject) => {
    fs.readFile(XML_FILE_PATH, 'utf8', (err, data) => {
      if (err) {
        if (err.code === 'ENOENT') {
          // If file doesn't exist, create a new XML structure
          const defaultData = { notes: { note: [] } };
          const builder = new xml2js.Builder();
          const xml = builder.buildObject(defaultData);
          
          fs.writeFile(XML_FILE_PATH, xml, (writeErr) => {
            if (writeErr) {
              reject(writeErr);
            } else {
              resolve(defaultData);
            }
          });
        } else {
          reject(err);
        }
      } else {
        const parser = new xml2js.Parser({ explicitArray: false });
        parser.parseString(data, (parseErr, result) => {
          if (parseErr) {
            reject(parseErr);
          } else {
            // Ensure notes.note is always an array
            if (result.notes && result.notes.note && !Array.isArray(result.notes.note)) {
              result.notes.note = [result.notes.note];
            }
            if (!result.notes) {
              result.notes = { note: [] };
            }
            if (!result.notes.note) {
              result.notes.note = [];
            }
            resolve(result);
          }
        });
      }
    });
  });
};

const writeXMLFile = (data) => {
  return new Promise((resolve, reject) => {
    const builder = new xml2js.Builder();
    const xml = builder.buildObject(data);
    
    fs.writeFile(XML_FILE_PATH, xml, (err) => {
      if (err) {
        reject(err);
      } else {
        resolve();
      }
    });
  });
};

// Generate a unique ID
const generateId = () => {
  return Date.now().toString(36) + Math.random().toString(36).substr(2, 5);
};

// API Routes

// Get all notes
app.get('/api/notes', async (req, res) => {
  try {
    const data = await readXMLFile();
    res.json(data.notes.note || []);
  } catch (err) {
    console.error('Error reading notes:', err);
    res.status(500).json({ error: 'Failed to get notes' });
  }
});

// Get notes by username
app.get('/api/notes/user/:username', async (req, res) => {
  try {
    const username = req.params.username;
    const data = await readXMLFile();
    
    const userNotes = data.notes.note.filter(note => note.username === username);
    res.json(userNotes);
  } catch (err) {
    console.error('Error reading notes by username:', err);
    res.status(500).json({ error: 'Failed to get notes by username' });
  }
});

// Get a note by ID
app.get('/api/notes/:id', async (req, res) => {
  try {
    const id = req.params.id;
    const data = await readXMLFile();
    
    const note = data.notes.note.find(note => note.id === id);
    if (!note) {
      return res.status(404).json({ error: 'Note not found' });
    }
    
    res.json(note);
  } catch (err) {
    console.error('Error reading note by ID:', err);
    res.status(500).json({ error: 'Failed to get note' });
  }
});

// Create a new note
app.post('/api/notes', async (req, res) => {
  try {
    const { title, content, username } = req.body;
    
    if (!title || !content || !username) {
      return res.status(400).json({ error: 'Title, content, and username are required' });
    }
    
    const data = await readXMLFile();
    
    const newNote = {
      id: generateId(),
      title,
      content,
      username,
      createdAt: new Date().toISOString()
    };
    
    if (!data.notes) {
      data.notes = { note: [] };
    }
    
    if (!data.notes.note) {
      data.notes.note = [];
    }
    
    data.notes.note.push(newNote);
    await writeXMLFile(data);
    
    res.status(201).json(newNote);
  } catch (err) {
    console.error('Error creating note:', err);
    res.status(500).json({ error: 'Failed to create note' });
  }
});

// Update a note by ID
app.put('/api/notes/:id', async (req, res) => {
  try {
    const id = req.params.id;
    const { title, content } = req.body;
    
    if (!title && !content) {
      return res.status(400).json({ error: 'Title or content is required' });
    }
    
    const data = await readXMLFile();
    
    const noteIndex = data.notes.note.findIndex(note => note.id === id);
    if (noteIndex === -1) {
      return res.status(404).json({ error: 'Note not found' });
    }
    
    // Update only the provided fields
    if (title) {
      data.notes.note[noteIndex].title = title;
    }
    
    if (content) {
      data.notes.note[noteIndex].content = content;
    }
    
    // Add updated timestamp
    data.notes.note[noteIndex].updatedAt = new Date().toISOString();
    
    await writeXMLFile(data);
    
    res.json(data.notes.note[noteIndex]);
  } catch (err) {
    console.error('Error updating note:', err);
    res.status(500).json({ error: 'Failed to update note' });
  }
});

// Delete a note by ID
app.delete('/api/notes/:id', async (req, res) => {
  try {
    const id = req.params.id;
    const data = await readXMLFile();
    
    const noteIndex = data.notes.note.findIndex(note => note.id === id);
    if (noteIndex === -1) {
      return res.status(404).json({ error: 'Note not found' });
    }
    
    // Remove the note
    const deletedNote = data.notes.note.splice(noteIndex, 1)[0];
    
    await writeXMLFile(data);
    
    res.json({ message: 'Note deleted successfully', deletedNote });
  } catch (err) {
    console.error('Error deleting note:', err);
    res.status(500).json({ error: 'Failed to delete note' });
  }
});

// Start the server
app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});

module.exports = app;
