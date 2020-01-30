reset(arg) {
  if(arg) return;
}

short() {
  return "A small sprout of a green plant";
}

id(str) {
  return str == "sprout";
}

long() {
  write("A small, weak-looking green sprout grows from the ground. Seems that this\n" + 
        "sprout has grown from a newly-planted seed or root. The sprout sways sofly\n" + 
        "in the weak forest wind. Nothing can be done with the sprout in this stage\n" + 
        "of its lifespan. You will have to wait longer that it grows bigger in size.\n");
}

get() {
  return 0;
}

query_weight() {
  return 1;
}
