id(str) { if (str == "floor") return 1; }

long() { write("the floor"); return 1; }

hit_with_spell(dam, type) {
  if (type == 1) { /* Eli fire dama */
	write("Jees");
	return 1;
  }
}

reset(arg) {
  enable_commands();
}
