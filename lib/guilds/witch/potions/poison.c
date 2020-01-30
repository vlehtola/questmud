int damage,time;
object tp;

reset(arg) {
  if(arg) { return; }
}

start(int dama, object ob) {
  damage = dama+random(dama);
  time = dama*3;
  tp = ob;
  if(present("poison_object", tp)) {
          destruct(this_object()); return 1; }

  call_out("damage", 15);
  call_out("end_poison", time);
  move_object(this_object(), tp);
  return 1;
}

id(str) { return str == "poison_object"; }
drop() { return 1; }
get() { return 0; }

damage() {
        if(tp->query_ghost()) { destruct(this_object()); return 1; }
        tell_object(tp, "You feel the poison burning in your veins.\n");
        say(tp->query_name()+ " is suffering badly from poison.\n",tp);
        tp->hit_with_spell(random(10)+damage, "poison");
        if(tp->query_ghost()) {
    destruct(this_object());
    tell_object(tp, "As you die, the poison leaves from your body.\n"); return 1; }
    if(random(15) == 0) {
        call_out("end_poison", 5);
        return 1;
}
        call_out("damage", 15);
        return 0;
}

query_poison() {
        return this_object();
}
stop() {
        tell_object(tp,"You feel cured from poison.\n");
                destruct(this_object());
return 1;
}

end_poison() {
        tell_object(tp, "Your organism manages eliminate the poison.\n");
        destruct(this_object());
return 1;
}
