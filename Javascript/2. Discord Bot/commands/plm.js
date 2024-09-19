import { SlashCommandBuilder } from "discord.js";

const data = new SlashCommandBuilder();
data.setName('PLM');
data.setDescription("I'm in danger...CHUCKLES");

export async function execute(interaction) {
    await interaction.reply("What's up Doc");
}