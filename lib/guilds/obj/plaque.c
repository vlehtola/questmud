short() { return "A metal plaque is hanging on the wall"; }
long() {
  write("Available commands:\n");
  write("  info           - Shows stat bonuses for levels\n");
  write("  list           - Displays the skills available on current level\n");
  write("  list level <x> - Lists the skills available on level <x>\n");
  write("  list all       - Displays the skills available at the maximum level\n");
  write("  join           - Join the guild\n");
  write("  cost           - Checks if you have enough free exp to advance\n");
  write("  lead           - Try and lead this guild\n");
  write("  train <skill> to <skill_level>\n");
  write("                 - Start training <skill> to <skill_level>\n");
  write("  advance        - Advance a level in this guild.\n");
  write("  requirements   - Displays the requirements for the whole guild\n");
  write("  teach <skill> to <name>\n");
  write("                 - Tries to teach the skill <skill> to <name>\n");
  return 1;
}

id(str) { return str == "plaque"; }



get(str) {
    if (str == "plaque") {
        write("You can't take the plaque.\n");
        return 1;
    }
    return 0;
}

