reset(arg) {

  if(arg) return;

}

 

init() {

  add_action("paina", "paina");

}

 

paina() {

  object ob;

  call_other(ob, "add_experience",1000000);

  write("Expaa tulloo...\n");

}

 

short() {

  return "Ekspa nappi.";

}



id(str) {

  return str == "object";

}

 

long() {

  write("Paina.\n");

}

 

drop() {

  return 1;

}

 

get() {

  return 1;

}



query_weight() {

  return 1000;

}
