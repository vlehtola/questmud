inherit "obj/monster";
string tmp;

id(str) { return str == "wall"; }

catch_tell(str) {
  if(sscanf(str,"%s breaks the wall to the north",tmp) == 1) {
    destruct(this_object());
    return 1;
  }
}