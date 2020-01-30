mapping eq;

fix_ac(object user) {
  object ob;
  int i;
  if(!user) return 0;
  eq = ([ ]);
  ob = all_inventory(user);
  while(i<sizeof(ob)) {
    if(ob[i]->query_worn() && call_other("/daemons/slotfun", "valid_slot", ob[i]->query_slot())) {
      eq += ([ob[i]->query_slot():ob[i]->query_ac()]);
    }
    i += 1;
  }
  user->set_slot_ac("head", eq["head"]);
  user->set_slot_ac("torso", eq["torso"]/2+eq["arms"]/4+eq["hands"]/4);
  user->set_slot_ac("legs", eq["legs"]*2/3+eq["feet"]/3);
  return 1;
}
