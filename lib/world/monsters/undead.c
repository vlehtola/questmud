inherit "obj/monster";

set_nam(n) {
  string str;
  int i;
  i = random(3);
  if(i==0) str = "skeleton";
  if(i==1) str = "zombie";
  if(i==2) str = "ghoul";
  set_name(str);
  set_short("Wandering "+str+" of "+capitalize(n));  
  set_alias(n);
  set_undead(1);
}

set_lvl(l) {
  set_level(l);
  set_aggressive(1);
  set_al(-50);
  set_resists("electric", 50);
  set_resists("cold", 50);
  set_resists("asphyxiation", 100);
  set_resists("poison", 100);
  set_resists("psionic", 100);
  set_exp(query_exp()/2);
}

reset(arg) {
  ::reset(arg);
}
