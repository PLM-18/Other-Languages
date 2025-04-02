const fs = require('fs')
const {parseString, Builder} = require('xml2js');

const xml = fs.readFileSync("database.xml").toString();
parseString(xml, function(err, data){
    console.dir(data.people.person);
});