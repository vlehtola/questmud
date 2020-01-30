object uhri;
int damage;

/* tekee uhrille damagen verran iskua */

start(ob,i) {
  if(!ob || i < 5) return;
  if(!uhri) {
    uhri = ob;
    shadow(uhri, 1);
    print_wound_desc();
    call_out("bleed", 0);
  }
  else { tell_object(uhri, "Your blood loss increases!\n"); }
  damage += i;
  if(damage > 250) damage = 250;
}

remove_bleeding() {
  if (uhri) tell_object(uhri, "The bleeding stops.\n");
  if (this_object()) destruct(this_object());
  return 1;
}

death(arg,arg2,arg3,arg4) {
  uhri->death(arg,arg2,arg3,arg4);
  remove_bleeding();
}

bleed() {
  string str;
  int dam;
  /* 1/4 damagesta / rnd */
  if(damage == 0) {
    remove_bleeding();
    return 1;
  }
  dam = damage/2;
  if(dam > 9) str = "";
  if(dam > 20) str = " a lot";
  if(dam < 10) str = " a little";
  tell_object(uhri, "Your wounds bleed"+str+".\n");
  tell_room(environment(uhri), uhri->query_name()+"'s wounds bleed.\n", ({uhri}));
  if(dam < 100) dam = damage;
  if(uhri->query_npc() && uhri->query_hp() <= dam) {
    remove_bleeding();
    return 1;
  }
  uhri->reduce_hp(dam);
  damage -= dam;
  call_out("bleed", 3);
}

print_wound_desc() {
  string str;
  if(damage <10) str = "scratch";
  if(damage <30) str = "little wound";
  if(damage <70) str = "nasty wound";
  if(damage <140) str = "deep wound";
  if(damage <201) str = "GAPING wound";
  
  tell_object(uhri, "You receive a "+str+" which starts to bleed!\n");
  tell_room(environment(uhri), uhri->query_name()+" wounds start to bleed!\n",
         ({uhri}));
}

query_bleeding() { return this_object(); }

