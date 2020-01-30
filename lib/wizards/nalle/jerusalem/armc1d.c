inherit "room/room";
 
object flaski1,flaski2;

reset(arg) {
  if(arg) return;
  flaski1 = clone_object("/wizards/nalle/potion.c");
  move_object(flaski1, this_object());
  flaski2 = clone_object("/wizards/nalle/flaskijuu.c");
  move_object(flaski2, this_object());
  add_exit("up","wizards/nalle/jerusalem/armc1");
  short_desc = "In a secret place";
  long_desc =
"You have entered a cold and humid place that has remained\n" +
"conclealed from prying eyes for decades, maybe centuries now.\n" +           
"Amongst some rubble you notice a couple of flasks that have \n" +
"remained in one piece.\n";
}


