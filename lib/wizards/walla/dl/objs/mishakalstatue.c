short() { return "A statue of Mishakal, godess of healing"; } 
 
long(str) {
    write("The statue of Mishakal makes your body tingle with warmth.\n");
    write("You could almost here it speak words of ancient wisdom. Even more\n");
    write("peculiar is that it smiles at you, almost as if it knew you'd arrive.\n");
    write("In your mind you hear words saying softly:\n");
    write("'Bring me back my disks and I shall reward you.\n");
  return;
}
 
id(str) { return str == "statue"; }
 
get(str) {
    if (str == "statue") {
        write("Now, that wouldn't be appropriate, would it?\n");
    return 0;
 }
    return 0;
}
