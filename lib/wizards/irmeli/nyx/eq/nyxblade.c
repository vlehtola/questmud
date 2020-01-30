inherit "obj/weapon";

start() {
    set_class(10);
    set_sub_type("claymore");
    set_short("The claymore called 'Firestorm' <emitting heat>");
    set_long("The claymore is made for the hands of immortals, hands which\n"+
             "can't burn. It's red, hot, blade glows with great heat and\n"+
             "occationally bursts in flames during combat.\n");
  
}

hit() {
  if(!wielded_by | !wielded_by->query_attack()) return;
if(random(13)) return;
  tell_room(environment(wielded_by), "The burning claymore gives a SHOCK "+
        "to "+wielded_by->query_attack()->query_name()+" as the HEATWAVE runs "+
        "through "+wielded_by->query_attack()->query_name()+"'s BODY!.\n");
 wielded_by->query_attack()->hit_with_spell(random(40)+10,1);
  return 1;
}
