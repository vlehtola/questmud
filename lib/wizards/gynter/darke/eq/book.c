id(str) {
 return str == "book";
}

short() {
  return "A shimmering book of laws";
}

long() {
  write("This is one of the few copies that exist.\n");
  write("It contains the laws of the Dark Elfs.\n");
  write("Written in their language.\n");
}

query_weight() {
  return  1;
}

get() {
  return 1;
}

init() {
  add_action("read_book", "read");
}
read_book(str) {
  if(str == "book") {
    if(this_player()->query_int() < 70) {
      write("As you open the book of laws a surge goes through your\n");
      write("whole body causing you to drop the book.\n\n");
      write("When the book hits the ground it dissapears.\n");
      this_player()->hit_with_spell(300);
      destruct(this_object());
    } else {
      write("As you open the book of laws a surge goes through your\n");
      write("arms and you almost drop the book. But through your incredible\n");
      write("willpower you manage to keep your grip and you start reading.\n\n\n\n");
      write("The eight commandments for the Dark Elves!\n\n");
      write("1. You shalt not have any other god besides me!\n");
      write("   The Spider-queen Lloth.\n");
      write("2. You shalt not use your dark arts on others that\n");
      write("   are of your own kind.\n");
      write("3. You Shalt not steal or commit murder unless you\n");
      write("   are absolutely sure you will not get caught.\n");
      write("4. You shalt eat the hearts of your foes so that you\n");
      write("   can gain their strength.\n");
      write("5. You shalt show your seniors the gravest respect.\n");
      write("6. If you get over the age of reconning you shalt go\n");
      write("   to the dyinggrounds so that you do not weaken the rest.\n");
      write("7. You shalt not think of anyone better than yourself.\n");
      write("8. You shalt not be an optimist, their ways are of good.\n");
      this_player()->set_quest("Read the Book of Laws");
      destruct(this_object());
    }
  }
}