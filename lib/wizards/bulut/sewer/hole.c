short() { return "A ventilation hole is here."; }
init() {
add_action("enter", "enter");
}

long(str) {
    write("This is a ventilation hole, builded on hard looking rocks.\n");
    write("The smell is really irritating'.\n");
    return;
}


id(str) { return str =="hole"; }




enter() {
 write("You shiver as you carefully start to climb down the hole.\n");
 write("The aroma of the rotten water allmost makes you throw up.\n");                                      
  move_object(this_player(), "/wizards/bulut/sewer/falling.c");
  call_out("climb", 4);
  call_out("slip", 8);
  call_out("falling1", 12);
  call_out("falling2", 16);
  call_out("falling3", 20);
  call_out("ground", 24);
return 1;
}



climb() {
write("You place your foot on a safe looking crack and start to descend.....\n\n");
return 1;
}

slip() {
write("OOOPS! Your foot slips from the crack,\n and you decide to take the QUICK way down!\n\n");
return 1;
}

falling1() {
write("Wheeeeeeeee.. this is gonna hurt when you hit the ground..\n\n");
return 1;    }

falling2() {
write("As you fall, the smell of the sewers start to tickle your nostrils... YUCK!\n\n");
return 1;    }

falling3() {
write("You can see some light below.. And you have to think.. is this your end?\n\n");
return 1;    }

ground() {
write("SPLASH!!! You become soaken wet from the water.. \n Yuck, the smell is even worse here.. \n");
write("But you are satisfied what has happened.. \n afterall.. You are still alive from that nasty fall..\n");
 move_object(this_player(), "/wizards/bulut/sewer/sewer1.c");
return 1;
         }


