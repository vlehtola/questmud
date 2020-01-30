inherit "room/key";

id(str) { if (str == "key") return 1; }

short() { return "A shining mithril key"; }

long() { write("Shining mithril key with red rock on it.\n"); }

reset() {
  set_door_file("/wizards/moonstar/areas/wasteland/fortress/yard13");

  set_key_code("999");
}

get() { return 1; }

query_weight() { return 20; }
