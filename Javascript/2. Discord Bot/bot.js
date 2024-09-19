import { Client, Events, GatewayIntentBits } from 'discord.js';
import { config } from 'dotenv';
import * as plm from './commands/plm'
config();

const client = new Client({
    // what is allowed to do
    intents: [GatewayIntentBits.Guilds],
});

function readyDiscord(){
    console.log('...' + client.user.tag)
}

client.once(Events.ClientReady, readyDiscord);

client.login(process.env.TOKEN);