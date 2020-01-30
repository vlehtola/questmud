object tamer, animal, tamer_ob;

start(ob, ani) {
        tamer = ob;
        animal = ani;
        tamer_ob = present("tamer_obj", tamer);
        shadow(animal, 1);
}

add_exp(arg) {
  if (arg < 0) { return; }
  tamer->add_exp(arg);
  return;
}
death(arg) {
 if(arg == !animal) {
call_other(tamer_ob, "animal_death");
animal->death();
}
}

query_animal_ob() {
        return this_object();
}
