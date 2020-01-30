object tp;
int still;
string tmp;

start(ob) {
  tp = ob;
tell_object(tp,"You feel a strange throbbing in your stomach.\n");
  call_out("stage_two", 21+random(15));
  return 1;
}

stage_one() {
tell_object(tp,"You start feeling a bit nauseous.\n");

if(sscanf(file_name(environment(tp)), "%s/adventurers_hall", tmp) ||
   sscanf(file_name(environment(tp)), "%s/tavern", tmp) ||
   tp->query_ghost() ||
   sscanf(file_name(environment(tp)), "%s/inn", tmp))   { 
tell_object(tp,"The inn's calm atmosphere makes you feel better and the pain eases.\n");
destruct(this_object());
return 1;
                                                        }
call_out("stage_two", 21);
return 1;
}

stage_two() {
object *puuh;
puuh=allocate(1);
puuh[0]=tp;
tp->reduce_hp(66);
tell_object(tp,"Your vision blurs and you feel something blocking your throat.\n");
tell_object(tp,"You cannot help throwing up and notice blood in the vomit.\n");
tell_room(environment(tp),tp->query_name()+" seems very sick and throws up.\n",puuh);

if(sscanf(file_name(environment(tp)), "%s/adventurers_hall", tmp) ||
   sscanf(file_name(environment(tp)), "%s/tavern", tmp) ||
   tp->query_ghost() ||
   sscanf(file_name(environment(tp)), "%s/inn", tmp))   { 
tell_object(tp,"The inn's calm atmosphere makes you feel better and the pain eases.\n");
destruct(this_object());
return 1;
                                                        }
call_out("stage_three", 21);
return 1;
}

stage_three() {
object *puuh;
puuh=allocate(1);
puuh[0]=tp;
tp->reduce_hp(33);
tell_object(tp,"You fail to catch breath as you feel something slithering up your throat.\n");
tell_room(environment(tp),tp->query_name()+" falls to "+tp->query_possessive()+" knees and wails in agony.\n",puuh);

if(sscanf(file_name(environment(tp)), "%s/adventurers_hall", tmp) ||
   sscanf(file_name(environment(tp)), "%s/tavern", tmp) ||
   tp->query_ghost() ||
   sscanf(file_name(environment(tp)), "%s/inn", tmp))   { 
tell_object(tp,"The inn's calm atmosphere makes you feel better and the pain eases.\n");
destruct(this_object());
return 1;
                                                        }
call_out("stage_four", 20+random(10));
return 1;
}

stage_four() {
object larvae;
object *puuh;
puuh=allocate(1);
puuh[0]=tp;

larvae=clone_object("/wizards/nalle/misc/larva");
if(sscanf(file_name(environment(tp)), "%s/adventurers_hall", tmp) ||
   sscanf(file_name(environment(tp)), "%s/tavern", tmp) ||
   tp->query_ghost() ||
   sscanf(file_name(environment(tp)), "%s/inn", tmp))   { 
tell_object(tp,"The inn's calm atmosphere makes you feel better and the pain eases.\n");
destruct(this_object());
return 1;
                                                        }
tell_object(tp,"You scream in horror as worm-like creature extracts itself from your mouth.\n");
tell_room(environment(tp),tp->query_name()+" collapses to the ground as a blood-covered larva slithers from "+tp->query_possessive()+" mouth.\n",puuh);
larvae->set_short("A blood covered larva, incubated in "+tp->query_name());  
larvae->set_level((int) tp->query_level()/3);  

move_object(larvae, environment(tp));
destruct(this_object());
return 1;
}

