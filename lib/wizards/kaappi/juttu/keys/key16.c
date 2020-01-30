inherit "room/key";
inherit "room/houses/keys/key_base";
reset() { set_key_code("2112"); }
query_auto_load() { return "/room/houses/keys/key16.c:"; }
