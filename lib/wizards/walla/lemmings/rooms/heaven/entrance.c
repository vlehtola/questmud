inherit "room/room";
int deeth;

init() {
  ::init();
  add_action("ring", "ring");
  add_action("say", "say");
  add_action("touch", "touch");

}

ring(str) {
  if(str != "bell") return;
  write("You ring on the bell.\n");
  say(""+this_player()->query_name()+" rings on the bell.\n");
  call_out("portilta_vastataan",4);
  return 1;
}

say(str) {
   if(str != "yes") return;
   write("A voice booms: 'Very well, let me open the gates.\n");
   say(""+this_player()->query_name()+" negociates with the presence, and seems to get accepted.\n");
   say("The pearly gates start to swing open.\n");
   call_out("portti_aukeaa",3);

}

touch(str) {
   if(str != "gates") return;
   write("You touch the pearly gates, and an electric shock runs through your body.\n");
   deeth = 21000;
   this_player()->reduce_hp(deeth);
   return 1;
}


int portilta_vastataan() {
    tell_room(this_object(),
             "A white presence surrounds you, and you feel that it's gaze penetrates\n"+
             "your soul.\n");
    call_out("portilta_vastataan_2",2);
    return 1;

}

int portilta_vastataan_2() {
    tell_room(this_object(),
             "A deep booming voice asks: 'Why have you come here?'\n");
    call_out("portilta_vastataan_3",2);
    return 1;

}

int portilta_vastataan_3() {
    tell_room(this_object(),
             "The voice continues: 'Have you specified an appointment with the one in charge?'\n");
    return 1;
}

int portti_aukeaa() {
    tell_room(this_object(),
            "The pearly gates start swinging open, and you can see a brightly lit path before you.\n");
    add_exit("north","/wizards/walla/workroom");

}    
  

  reset(arg) {
  short_desc = "In a bright white environment";
  long_desc =
"You have arrived at a place where the dominant color is the brightest white you've\n"+
"ever seen. You are standing on something that appears to be a cloud, that feels soft\n"+
"to the touch, and you can even put your hand through it. Yet it seems to be rigid enough \n"+
"to hold your weight. The landscape is white all over, and the only thing breaking the\n"+
"whiteness is a white wall, that seems to stretch for endless distances to both sides.\n"+
"In the middle of the wall, are huge gates, made out of the finest pearlescent materials.\n"+
"The gates stretch as high as your eyes can see. The gates seem to be almost in reach for\n"+
"you to touch them. A tingling feeling in your fingers almost welcome the possibility of\n"+
"touching the gates.\n";

  items = allocate(6);
  items[0] = "gates";
  items[1] = "The gates look pearlescent, and has runes incrested in the vertical bars.";
  items[2] = "runes";
  items[3] = "The runes are written in a language you don't understand.";
  items[4] = "bars";
  items[5] = "The bars are made out of a pearlescent gilded material that appears unearthly";
  

}


