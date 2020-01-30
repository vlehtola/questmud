inherit "room/room";
object monster;



reset(arg) {
  if(arg) return;
  if(!present("zombie") && !random(1)) {
     move_object(clone_object("/wizards/devil/area/mobit/emperor.c"), this_object());
}       
 add_exit("south","/wizards/devil/area/huoneet/r62.c");

 short_desc = "Emperors living place";
 long_desc =  "You have arrived to the end of the path.\n"+
"It is dark and you can't see clearly where you are at the minute, but you\n"+
"start to get a REALLY bad feeling about this place. The path is in a good\n"+ 
"condition in here, much better than the path that you just walked on.\n"+
"Suddenly you notice that his is the living place of the Emperor and you start\n"+
"to regret having come here.\n";

}
