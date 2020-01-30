inherit "obj/weapon"; 
 
reset(arg) {
    ::reset(arg);
    set_name("hammer");
    set_short("Hammer of Might <Frost Bite>");
    set_long("This hammer freezes stuck to your hand as you hold it.\n");
    set_value(10000);
    set_weight(690);
    set_hit_func(3);
}
 
hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(3) != 0) return;
  tell_room(environment(wielded_by), "The hammer beats the opponent making bits and"+
        "pieces fly out of "+wielded_by->query_attack()->query_name()+"!\n");
  wielded_by->query_attack()->hit_with_spell(random(210)+69,5);
  return 1;
}
 
 

