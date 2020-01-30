inherit "room/key";
inherit "room/houses/keys/key_base";
reset() { set_key_code("30004"); }
query_auto_load() { return "/room/houses/keys/key1.c:"; }
