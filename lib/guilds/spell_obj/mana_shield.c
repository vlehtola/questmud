object user;
int duration, effect;

hit_player(int dam, arg2,arg3,arg4,arg5,arg6) {
        int damage;
        damage = dam;
        user->reduce_sp(damage*2);
        if(user->query_sp() < 10) { user->set_sp(0); tell_object(user, "The shimmering shield around you vanished!\n"); destruct(this_object()); }
        return 1;
}

start(object ob, int bonus) {
  user = ob;
  duration = bonus;
  tell_object(user, "You are protected by a shimmering shield.\n");
  shadow(user, 1);
  call_out("end_mana_shield", duration);
}

query_mana_shield() {
  return this_object();
}

end_mana_shield() {
  tell_object(user, "The shimmering shield around you vanishes!\n");
  destruct(this_object());
}

death(arg) {
  user->death(arg);
  if(this_object()) destruct(this_object());
  return 1;
}