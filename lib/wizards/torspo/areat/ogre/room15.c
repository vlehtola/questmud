inherit "room/room";

reset(arg) {

 if(!present("warrior")) {
   move_object(clone_object("/wizards/torspo/areat/ogre/monsters/ogre2.c"), this_object());
 }

  if(arg) { return; }
  add_exit("west", "/wizards/torspo/areat/ogre/room16.c");
  add_exit("east", "/wizards/torspo/areat/ogre/room20.c");
  add_exit("southeast", "/wizards/torspo/areat/ogre/room14.c");

   short_desc = "Fortress";
  long_desc = "This is the inner part of the fortress. Some small wooden huts stand around\n"+
              "the path and there is a well built under some palm trees. From here\n"+
              "can be seen the real size of the fortress and it really looks enormous.\n"+
              "Some logs and stone block the way to the northeast. They might be the\n"+
              "remainder of some ancient building.\n";
              "heart of the fortress even more of the ogres you encounter are in arms.\n"+
              "Most of them are wielding only primitive weapons such as clubs but some\n"+
              "wear different armours and lethal-looking maces.\n";
  items = allocate(4);
  items[0] = "well";
  items[1] = "Ordinary circle shaped well. It has been made of hard, gray stones and"+
             "some hard planks";
  items[2] = "trees";
  items[3] = "Long trunks and big leaves. Just some ordinary palms";
}
