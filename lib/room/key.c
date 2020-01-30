string code;

set_key_code(str) { code = str; }

query_key_code() {
  if("/obj/player"->query_no_savemode() && this_object()->query_house_key()) {
    write("House keys cannot be used in NOSAVE mode.\n");
    return 1;
  }
  return ""+code;
}

set_door_file(str,id) {
   code = call_other(str, "query_door_code", id);
}
