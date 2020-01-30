/* rupublast */
resolve(bonus, string target) {
  object ob, ob2;
  string target2;
  int effect,heal_to_self;
  if(!target) {
    write("Cast soul drain at who?\n");
    return 1;
  }
  ob = present(target, environment(this_player()));
  if (!ob) {
    write("No '"+capitalize(target)+"' here.\n");
    return 1;
  }
  if(!living(ob)) {
    write(capitalize(target)+" is not a living thing.\n");
    return 1;
  }
  if(ob->query_animal() || ob->query_undead()) {
    write(capitalize(target)+" doesn't have any soul.\n");
    return 1;
  }
  if (ob == this_player()) { write("Target cannot be yourself.\n"); return 1; }
  effect = this_player()->query_wis() + this_player()->query_int() + 20;
  effect += this_player()->query_skills("cast focus dark power");
  effect += this_player()->query_skills("cast minor necromancy");
  effect += this_player()->query_skills("cast dark power");
  write("You drain some of "+target+"'s life force.\n");
effect /= 2;
if(effect > 400)effect = 400;
  say(this_player()->query_name()+" drains some of "+target+"'s life force!\n");
  tell_object(ob, this_player()->query_name()+" drains some of your life force!\n");
  effect = ob->hit_with_spell(effect,0,this_player());
  this_player()->attack_object(ob);
  return 1;
}
