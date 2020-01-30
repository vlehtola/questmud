short() { return "A statue of the goddess Angelina"; }

long(str) {
    write("The statue of Angelina makes your body tingle with warmth.\n");
    write("You could almost hear it speak the words of ancient wisdom.\n");
    write("Even more peculiar is that it smiles at you, almost as if\n");
    write("it knew you'd arrive.\n");
  return;
}

id(str) { return str == "statue"; }

init() {
    add_action("pray", "pray");
}

pray(str) {
  if(str != "statue") return;
  write("Bless you, my dear child.\n");
  this_player()->set_quest("Pray to Angelina");
  return 1;
}

get(str) {
    if (str == "statue") {
        write("Now, that wouldn't be appropriate, would it?\n");
    return 0;
 }
    return 0;
}

