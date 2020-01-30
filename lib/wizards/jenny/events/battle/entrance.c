inherit "room/room";

reset(arg) {

  short_desc = "In the waiting room";
  long_desc = "A cosy looking waiting room. There are\n"+
              "lots of people waiting for battles to\n"+
              "start. Almost everyone is holding somekind\n"+
              "of weapons except mages who just calmly\n"+
              "meditate before using their magic\n";

  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
  set_not_out(1);
  set_light(3);

}

//muuta catch_tell call_outille kuhan on tehty event_ob
catch_tell(str) {

  if(str == "Master shouts: 'Let the battles begin!'") {
   add_exit("north","/wizards/jenny/events/battle/battle1.c");
     say("Master tells you: 'Go go go! kill everyone!'\n");
     command("look",this_player());
 }
return 1;
 }
