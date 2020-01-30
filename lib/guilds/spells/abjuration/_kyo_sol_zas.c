#define MASTERY_D "/daemons/mastery_d"

resolve(bonus, string target) {
  object ob, ob2;
  string target2;
  int effect;
  if(!target) {
    write("Cast force blow at who?\n");
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
  if (ob == this_player()) { write("Target cannot be yourself.\n"); return 1; }
  effect = this_player()->query_wis() + this_player()->query_int() + 20;
  effect += this_player()->query_skills("abjuration");
  effect += this_player()->query_skills("cast abjuration");
  effect += this_player()->query_skills("cast force");
  write("You force some of "+capitalize(target)+" life force.\n");
  effect /= 2;
  if(effect > 400)effect = 400;
  effect += MASTERY_D->mastery("mastery of shielding",this_player(),ob);

  say(this_player()->query_name()+" forces some of "+target+"'s flesh to rip apart!\n");
  tell_object(ob, this_player()->query_name()+" forces some of your flesh to rip apart!\n");
  this_player()->attack_object(ob);
  ob->hit_with_spell(effect,"physical",this_player());
  return 1;
}

