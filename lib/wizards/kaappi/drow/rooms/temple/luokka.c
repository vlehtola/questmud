inherit "room/room";

reset(arg) {

  if(arg) return;

  add_exit("stairs", "t18.c");

  short_desc = "A classroom";
  long_desc = "A huge and spacious room. There are nearly\n"+
              "30 desks placed around the classroom. A couple\n"+
              "of bookshelves are leaning against the walls.\n"+
              "Some drow priestesses are here studying.\n"+
              "They are so concentrated on their books that they\n"+
              "don't even notice as you enter the room.\n";
              
  set_light(1);
}
