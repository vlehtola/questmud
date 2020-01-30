get_time(str) {
  return 1;
}
ep_cost() { return 0; }
query_type() { return "neutral"; }

resolve_skill() {
  int i;
  i = this_player()->query_skills("dark lore");
write("So far you know that:\n");
write(
"- Your horde's hit points are the combined hit points of the corporeal\n"+
"  undeads in it. When one dies, horde's stats are re-calculated, and\n"+
"  the next one starts to take damage. Zombies get killed before skeletons.\n"+
"  Flesh golems get killed before zombies.\n");
if(i<10) return;
write(
"- The horde's abilities raise as more undeads join it. Skeletons,\n"+
"  wights and ghost increase it's strength, skills and combat capabilities.\n");
if(i < 20) return;
write(
"- If the corporeal part of the horde is killed, the ethreal part is\n"+
"  destroyed automaticly.\n");
if(i < 30) return;
write(
"- Zombies have much more hps than skeletons. They just stand still and take\n"+
"  hits, but they do it well. Zombies can use defensive skills.\n"+
"  Flesh golems are upgraded versions of zombies and they have many times\n"+
"  more hit points than zombies.\n");
if(i < 40) return;
write(
"- The amount of skeletons defines how many attacks your horde gets\n"+
"  in one round. Skeletons also add some strength to horde.\n"+
"  The amount of skeletons also affect the wraiths damage.\n");
if(i < 50) return;
write(
"- Wights increase the hordes knowledge and physical power granting\n"+
"  it better skills and making it more lethal in combat.\n");
if(i < 60) return;
write("- Ghosts add much strength to the hordes hits.\n");
if(i<70) return;
write("- Wraiths gaze the enemies of the horde, dealing cold damage.\n");
write("- The hidden subguilds are in the cemetary, try pushing the tombstones.\n");
if(i<80) return;
write(
"- Death knight generally upgrades the horde's abilities.\n"+
"   It also orders the horde to attack in one group.\n");
if(i<90) return;
write(
"- Cast unholy enchantments allows you to cast 3 different auras at your horde.\n"+
"  The red aura increases your horde's durability and the brown aura increases\n"+
"  the horde's physical and mental attributes. The blue aura makes your horde more\n"+
"  furious improving death knight's and wraith's special powers.\n");
if(i<100) return;
write(
"- Lich requires many skeletons' dark power to be created. It casts\n"+
"  offensive spells in combat. It's magical abilities are straightly\n"+
"  based on it's master's 'control greater undead' and 'control dark\n"+
"  magic' skills.\n");
  return 1;
}

fail_skill() {
  resolve_skill();
}
