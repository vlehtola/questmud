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
  write("flagpolen desci tähä\n");
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
        "Erkki notices the flag and arrives in a puss of smoke.\n");
move_object(clone_object("/wizards/walla/mobs/erkki.c"), 
            environment(this_object()));
}
 
 

