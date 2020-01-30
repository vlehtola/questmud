int lippu_ylhaalla=1;
 
reset(arg) {
 
  if(arg) return;
}
 
id(str) {
  return str == "flagpole";
}
 
short() {
  return "A huge flagpole";
}
  
long() {
  write("You see a huge flagpole, sleek and white, and atleast 50 feet high.\n");
  write("The flagpole has to strings, which are used to hoist and lower the flag\n");
  write("soaring high up in the air.\n");
}
 
query_weight() {
  return  1;
}
 
get() {
  return 0;
}
 
init() {
  add_action("lower","lower");
  add_action("hoist","hoist");
 
}
lower(str) {
  if(!str) return 0;
 
  if(str=="flag" && lippu_ylhaalla==2) {
  write("It is stuck, there is some rag up there.\n");
  return 1;
  }
 
  if(str == "flag") {
  if(!lippu_ylhaalla) {
  write("The flag has already been removed from the flagpole.\n");
  return 1;
  } else {
  write("You grab hold of the strings, and start lowering the flag. You feel the strings\n");
  write("start moving more rapidly as the flag gains momentum, and the skin starts to peel\n");
  write("off your fingers. As the flag comes into your reach, you carefully remove the flag\n");
  write("from its hooks, careful not to let the flag touch the ground, and tie the strings\n");
  write("around the flagpole, in order for it, not to slip off the pole.\n");
  call_out("klonaa_lippu", 1);
  lippu_ylhaalla = 0;
  return 1;
  }
 }
}
 
 
klonaa_lippu() {
  object flag;
  write("You take the flag into your hands, quickly fold it into a triangle, and tuck it\n");
  write("safely away into your inventory.\n");
  flag = clone_object("/wizards/walla/northern/stuph/evil_flag");
 move_object(flag, this_player()); 
  return 1;
}
 
 
hoist(string str)
{
 if(!str) return 0;
 
 if(str=="flag") {
  if(lippu_ylhaalla)
 write("A flag is already hoisted up.\n");
  else
 write("No point in that anymore, it has already been lowered.\n");
 return 1;
 }
 
 if(str == "rag")
  {
    if(lippu_ylhaalla)
    {
      write("A flag is already hoisted up.\n");
      lippu_ylhaalla = 1;
      return 1;
     }
      else
    {
   if(!present("hv0700123123",this_player()))
    return 0;
  write("You hoist the rag up the pole.\n");
  lippu_ylhaalla = 2;
  destruct(present("hv0700123123",this_player())); 
  call_out("kutsu_erkki",5);
  return 1;
    }
  }
}
 
 
int kutsu_erkki() {
tell_room(environment(this_object()),
        "A small dwarf suddenly appears, and introduces himself as Irthun.\n");
move_object(clone_object("/wizards/walla/northern/mobs/irthun.c"),
            environment(this_object()));
call_out("erkin_selitykset_1",5);
return 1;
}
 

int erkin_selitykset_1() {
tell_room(environment(this_object()),
         "Irthun says: 'So you have killed Khilarbhunaz, and set his soul\n"+
         "to peace at last. I thank you very much for that.'\n");
call_out("erkin_selitykset_2",5);
return 1;
}

int erkin_selitykset_2() {
tell_room(environment(this_object()),
         "Irthun says: 'I was thinking of reclaiming this place as my own\n"+
         "now that all evil is freed from this place. What do you think?'\n");
call_out("erkin_selitykset_3",5);
return 1;
}

int erkin_selitykset_3() {
tell_room(environment(this_object()),
         "Irthun says: 'If I could only get the crown of kings, then I\n"+
         "could rule this place, as it's righteous ruler.'\n");
call_out("erkin_eukko_appears",5);
return 1;
}

int erkin_eukko_appears() {
tell_room(environment(this_object()),
        "A female dwarf appears, and looks curiously at you.\n");
move_object(clone_object("/wizards/walla/northern/mobs/felur.c"),
            environment(this_object()));
call_out("erkin_akan_selitykset_1",5);
return 1;
}

int erkin_akan_selitykset_1() {
tell_room(environment(this_object()),
         "The female dwarf starts whining at Irthun and says:\n"+
         "'Irthun my love, you don't need a crown to rule this place.'\n");
call_out("erkin_selitykset_4",5);
return 1;
}

int erkin_selitykset_4() {
tell_room(environment(this_object()),
         "Irthun says: 'Of course i need my crown, now get out of here.\n"+
         "After all, I should know, no?'\n");
call_out("erkin_akka_vittuun",5);
return 1;
}

int erkin_akka_vittuun() {
tell_room(environment(this_object()),
         "The female dwarf mutters for a while, and turns her back\n"+
         "on Irthun and starts crying as she runs away.\n");
destruct(present("felur",environment( this_object() )));
call_out("erkin_selitykset_5",5);
}

int erkin_selitykset_5() {
tell_room(environment(this_object()),
         "Irthun says: 'Could you please get me the crown?\n"+
         "It would mean so much to me.'\n");
call_out("erkin_selitykset_6",10);
return 1;
}

int erkin_selitykset_6() {
tell_room(environment(this_object()),
         "Irthun says: 'I'm off to gather some resistance members,\n"+
         "when you've got the crown, come find me.\n");
call_out("erkki_lahtee_menee",4);
}

int erkki_lahtee_menee() {
tell_room(environment(this_object()),
         "Irthun looks around him, and stealthily disappears.\n");
destruct(present("irthun",environment( this_object() )));

}




