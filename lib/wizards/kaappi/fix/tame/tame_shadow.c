int aika, control, stay;
object aijys, elain, ahaa, puuh, recog, jooh;

// added by C. animals cannot carry unlimitedly
int query_weight(int weight) { 
  if(!elain || sizeof(all_inventory(elain)) > 25)
    return 1;
}

start(ob, ani) {
  aijys = ob;
  elain = ani;
  stay = 0;
  jooh = this_object();
  if (present("probe_tame_ob", aijys)) { active(); return 1;}
  recog = clone_object("/guilds/skill_obj/tame_recog.c");
  move_object(recog, aijys);
  recog->start(jooh, elain); /* quitin, safe quitin takia */
  shadow(elain, 1);
  control = aijys->query_skills("control animal");
  call_out("movecheck", 4);
  return 1;
}

active() {
 write(elain->short()+" senses the recent presence of another animal and backs up.\n");
 destruct(this_object());
 return 1;
}

breaktest() {
 if(control < elain->query_level()*4 && !random(6)) {
   write(elain->short()+" no longer seems to obey your commands.\n");
   say(aijys->query_name()+"'s animal no longer seems to obey "+
       aijys->query_possessive()+" commands.\n", aijys);
   destruct(recog);
   destruct(this_object());
 } 
}

movecheck() {
  if (!present(aijys, environment(elain)) && (stay != 21)) {
    move_object(elain, environment(aijys));
    tell_room(environment(aijys), elain->short()+" arrives.\n");
  }
  aika+=4;
  if (aika > control+10) { breaktest(); }
  call_out("movecheck", 4);
}

add_exp(arg) {
  if (arg < 0) { return; } 
  aijys->add_exp(arg);
  return;
}

death(arg) {
 destruct(recog); 
 destruct(this_object()); 
 return; 
}

catch_tell(str) {
    string master,kasky,kohde,masta,puff;
    if (!str) { return 1; }
    if (sscanf(str, "%s disappears in a puff of smoke.", masta) == 1) {
        if (masta == aijys->query_name()) { stay = 21; return; }}
    if (sscanf(str, "%s says 'follow'", masta) == 1) {
        if (masta == aijys->query_name()) { 
         stay = 0; 
         write(elain->short()+" will now follow you.\n");
        } return; }
    if (sscanf(str, "%s says 'stay'", masta) == 1) {
        if (masta == aijys->query_name()) { 
        write(elain->short()+" will wait for you here.\n");
        stay = 21;
        } return; }
    if (sscanf(str, "%s says 'attack %s'", master, kohde) == (2)) {
       if (!present(aijys,environment(elain))) { return; }
       if (master != aijys->query_name()) { return; }
       ahaa = present(lower_case(kohde),environment(elain)); 
       puuh = present(lower_case(kohde),environment(aijys)); 
       if (!ahaa) { return; }
       if(environment(elain)->query_property("no_kill")) return;
       tell_room(environment(aijys), elain->short()+
            " is ordered to attack "+ahaa->query_name()+"\n");
       elain->attack_object(ahaa);
       return 1;
      } 
}
