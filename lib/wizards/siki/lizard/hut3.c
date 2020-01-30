inherit "room/room";
object monster, monster2;

reset(arg) {

    if(arg) return; /* added by Celtron */

    if(!monster) {
       monster = clone_object("/wizards/siki/lizard/monsters/king");
       move_object(monster, this_object());
       }
    if(!monster2) {
       monster2 = clone_object("/wizards/siki/lizard/monsters/queen");
       move_object(monster2, this_object());
     }

  add_exit("north","/wizards/siki/lizard/hut2");


  short_desc = "A tiny straw hut";
  long_desc = "The walls are made of dry and thin straws. The ground is cold\n"+
              "and wet and there are some dead straws here and there. There is\n"+
              "a huge round oaken table in the middle of the room with two chairs.\n"+
              "On the southern wall is a small black and white painting.\n";

   items = allocate(10);
   items[0] = "painting";
   items[1] = "A black and white painting of a fishing lizardman";
   items[2] = "chairs";
   items[3] = "Huge oaken chairs with golden decorations";

   items[4] = "chair";
  items[5] = "Huge oaken chair with golden decorations";
  items[6] = "table";
  items[7] = "A round oaken table with a piece of paper on it";
  items[8] = "paper";
  items[9] = "A small dusty piece of paper with a short note on it:\n"+
             "\n"+
            "         'We can not help you with your\n"+
            "          problem. We are very sorry and\n"+
            "          hope that some adventurers can\n"+
            "          help you. This world is full of\n"+
            "          good adventurers, the worlds future\n"+
            "          is in good hands.'\n"+
            "\n"+
            "   Sincerely yours, Thelih, the Mayor of Duranghom";
   set_not_out(1);
}
