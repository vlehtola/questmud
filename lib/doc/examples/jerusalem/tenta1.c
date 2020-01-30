inherit "room/room";
object monster;

reset(arg) {

  if(arg) return;

  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/ilana");
    move_object(monster, this_object());
  }
 
  add_exit("out","wizards/nalle/jerusalem/jewb1");
  short_desc = "A dark tent";
  long_desc = "You entered a dark tent, furnished with a mahogany desk, a\n" +
              "large bookshelf and a chair. A woman is sitting on the chair\n" +
              "chanting to herself. She has flowing dark hair and azure blue\n" +
              "eyes. She is very beautiful, and seems to practice magic.\n";
}

