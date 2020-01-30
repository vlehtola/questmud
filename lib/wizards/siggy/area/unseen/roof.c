inherit "room/room";
object dragon;
reset(arg) {
    if(arg) return;
    add_exit("down","/wizards/siggy/area/unseen/uu35.c");
    set_not_out(3);
    short_desc = "The roof of the Unseen University";
    long_desc = 
        "You are in very very high place. You suddenly start feeling sick. Sometimes\n"
        + "the red dragon sits here watching around. The roof is very slippy and you\n" 
        + "should be careful to not to fall off, it would be a deadly drop. The sun\n"
        + "shines up here. You start to ponder what the heck are you doing here?\n";
    if(!dragon) {
    dragon = clone_object("/wizards/siggy/area/unseen/dragon");
    move_object(dragon, this_object());
    }
  }



