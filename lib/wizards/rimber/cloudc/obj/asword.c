inherit "obj/weapon";
int dam, i, plus, a = -50;
int sla, bb, bb1, sho, rank;

start() {
 set_class(9);
 set_sub_type("broad sword");
 set_name("sword");
 set_alias("sword");
 if(sho == 0) { set_short("A broad sword with a "+get_short(a)+" blade"); }
 if(sho == 1) { set_short("A broad sword with a "+get_short(a)+" blade <glowing>"); }
 set_long("Knights have used this sword in their battles and honored their foe after\n"+
  "honorable fight. The sword has the "+get_long(rank)+" rank by the knights order.\n");
 if(sla == 1) { set_slayer("angel"); }
 if(sla == 2) { set_slayer("demon"); }
}

hit() {
 if(!wielded_by || !wielded_by->query_attack()) { return; }
 if(random(101) > 88) {
  dam = plus+random(102);
   switch(a) {
  case 50 : write("The blade FLASHES and you strike it into the "+wielded_by->query_attack()->query_name()+"'s chest and twist hard.\n"+
   "You prepare for another strike. Long trail of flames come after the blade as\n"+
   "you SLASH it DEEP into the "+
     wielded_by->query_attack()->query_name()+"'s shoulder.\n"+
     wielded_by->query_attack()->query_name()+" howls in PAIN.\n");
     say(wielded_by->query_name()+"'s sword flashes brightly blinding you for a moment.\n"+wielded_by->query_attack()->query_name()+" howls in PAIN.\n");
     break;
    case -50 : write("You slash the sword towards the "+wielded_by->query_attack()->query_name()+
     "'s neck with a HUGE arc.\n"+
     "BLOOD spills around as your slash makes long nasty scratch to the "+
     wielded_by->query_attack()->query_name()+"'s neck.\n"+
     wielded_by->query_attack()->query_name()+" screams in PAIN.\n");
     say(wielded_by->query_name()+" slashes with a HUGE arc hitting "+wielded_by->query_attack()->query_name()+"'s neck.\nBlood spills around and "+wielded_by->query_attack()->query_name()+" screams in PAIN.\n");
     break;
   }
   if(wielded_by->query_attack()->query_alignment() < 0) {
   i = 1;
   call_out("change", 1);
   }
   if(wielded_by->query_attack()->query_alignment() > 0) {
   i = 0;
   call_out("change", 1);
   }
   if(random(120) < 50) { return 1; }
     if(wielded_by->query_attack()->query_alignment() > 0) {
      write("Sword seems to suck the blood from the blade.\n");
      wielded_by->add_ep(random(21));
    }
     if(wielded_by->query_attack()->query_alignment() < 0) {
     write("The sword feels warmer when the "+wielded_by->query_attack()->query_name()+"'s blood gets to the blade.\n");
      wielded_by->heal_self(random(102));
    }
   }
}

get_short(int a) {
 switch(a) {
 case -50 : sla = 1;
   return "blood red and FLAMING";
 case -49..-39 : sla = 0;
    return "glowing BLACK";
 case -38..-28 : return "BLACK";
 case -27..-17 : return "blood red";
 case -16..-6 : return "red";
 case -5..5 : return "two-edged";
 case 6..16 : return "clear";
 case 17..27 : return "bright";
 case 28..38 : return "WHITE";
 case 39..49 : sla = 0;
   return "glowing WHITE";
 case 50 : sla = 2;
  return "white and FLAMING";
 }
 return "FIERCELY BURNING";
}

int change() {
 if(a == 50) { return 1; }
 if(a == -50) { return 1; }
 if(i == 0) {
           a -= 1;
  if(a == -50) {
    write("The sword bursts in blood red flames.\n");
    say(wielded_by->query_name()+"'s sword bursts in blood red flames.\n");
  }
  else { write("The blade gets dimmer.\n");
    say(wielded_by->query_name()+"'s sword gets dimmer.\n");
  }
   reset();
 }
 if(i == 1) {
           a += 1;
  if(a == 50) {
    write("The blade bursts in white flames.\n");
   say(wielded_by->query_name()+"'s sword bursts in white flames.\n");
  }
 else { write("The blade gets brighter.\n");
  say(wielded_by->query_name()+"'s sword gets brighter.\n"); }
  reset();
 }
}

init() {
 ::init();
 add_action("honor", "honor");
}

honor(string str) {
 object ob;
 if(!wielded_by) { return; }
 if(sho == 1) { return; }
 if(a == 50 || a == -50) {
 if(str != "corpse") { return 1; }
 if(rank == 1000) { write("You kneel before the corpse but nothing happens.\n");
   return 1; }
 ob = present("corpse", environment(this_player()));
  write("You kneel before the corpse to honor his courage in battle.\n");
  say(wielded_by->query_name()+" kneels before the corpse.\n");
  if(a == 50) { write("Brilliant light from the sky hits directly at the corpse and takes it away.\n"); }
 if(a == -50) { write("The ground beneath the corpse opens and swallows the corpse.\n"); }
 bb = 1+random(10);
 write("The blade starts glowing.\n");
 say(wielded_by->query_name()+"'s sword starts glowing faintly.\n");
 sho = 1;
 call_out("aika", bb);
 destruct(ob);
 reset();
 return 1;
}
}

int aika() {
 write("The blade stops glowing after "+bb+" seconds.\n");
 say(wielded_by->query_name()+"'s sword stops glowing.\n");
 sho = 0;
 rank += bb;
 if(rank > 1000) { rank = 1000; }
 reset();
}
get_long(int rank) {
 switch(rank) {
  case 0..50 : return "soldier";
  case 51..150 : plus = 30;
    return "squire";
  case 151..300 : plus = 60;
    return "knight";
  case 301..430 : plus = 90;
    return "rider";
  case 431..600 : plus = 120;
     return "honorable knight";
  case 601..800 : plus = 160;
     return "lord";
  case 801..999 : plus = 180;
     return "warlord";
  case 1000 : plus = 205;
   if(a == 50) { return "God's hand"; }
    if(a == -50) { return "Devil's hand"; }
 }
 return "scum";
}
