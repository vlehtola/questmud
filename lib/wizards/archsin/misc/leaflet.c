get() { return 1; }
id(str) { if(str == "leaflet") return 1; }
short() { return "Leaflet about 'Con"; }
long() { write("\nQuestCon 9.3.2002 at Espoo, Finland!\nFor more info, see 'help mudcon'.\n\n"); }

not_wanted_anymore() {
  destruct(this_object());
  return 1;
}

reset() {
  call_out("not_wanted_anymore", 120);
}
