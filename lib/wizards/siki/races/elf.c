query_race_name() { return "elf"; }
query_creator() { return "mudlib"; }
query_upkeeper() { return "neophyte"; }
/* all functions are optional. */

reset(arg) {
  if(arg) return;
}

short() {
  return "Alright, this object has a short";
}

/* id, this means the calling name of the object. you must put it */
/* if you want that object is lookable or gettable etc */
id(str) {
  return str == "object";
  /* we can also return str == name || str == alias || str == alt_name; etc */
}

long() {
  write("This is the LONG desc.\n");
}

/* 1 can't drop, 0 can drop. see get() */
drop() {
  return 1;
}

/* 1 can be taken, 0 can't. if get() function doesn't exist, 0 is returned. */
get() {
  return 1;
}

/* uh, heavy */
query_weight() {
  return 1000;
}

/* add your own functions etc. this file proves only, that objects can be simple */
/* and easily done. coding is fun anyway. //Celtron */

