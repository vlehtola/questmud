
cmd_testguilds() {
string *files;
string *index;
mapping skills;
object pager;
string result, resulti;
int i, ii;
files = ({ "/guilds/abjurer/abjurers", "/guilds/abjurer/masters_of_abjuration.c", "/guilds/abjurer/masters_of_sorcery.c", "/guilds/abjurer/masters_of_vulnerability.c", "/guilds/channel/appr_cleric", "/guilds/channel/adept_cleric", "/guilds/channel/high_cleric", "/guilds/psi/psiguild", "/guilds/psi/fighter_psionicists", "/guilds/psi/caster_psionicists",
           "/guilds/necro/base_guild", "/guilds/necro/animators","/guilds/necro/control1","/guilds/necro/control2", "/guilds/necro/dark_power", "/guilds/necro/necro","/guilds/necro/unholy_lords",
           "/guilds/mage/adv_mages","/guilds/mage/apprmage","/guilds/mage/arcaners","/guilds/mage/electric_adept","/guilds/mage/fire_adept","/guilds/mage/ice_adept","/guilds/mage/illusionists","/guilds/mage/master_mage","/guilds/mage/merchant","/guilds/mage/navigator","/guilds/mage/scroll_scribblers",
           "/guilds/fighter/acrobats","/guilds/fighter/axes","/guilds/fighter/barbarian","/guilds/fighter/berserker","/guilds/fighter/blades","/guilds/fighter/bludgeons","/guilds/fighter/body_builders","/guilds/fighter/defender","/guilds/fighter/fighter","/guilds/fighter/ranger","/guilds/fighter/smith","/guilds/fighter/veterans","/guilds/fighter/warrior","/guilds/fighter/weapon_master",});
result = sprintf("Total of %-1d Guilds\n", sizeof(files));
for ( i = 0 ; i < sizeof(files); i++) {
	skills=files[i]->skill_list(files[i]->guild_max_level());
	if(skills)index=m_indices(skills);
	result += sprintf("\nGuild Name: %-25s\nGuild Max Lvl:%-5d\nGuild Stats:%10s\n",
	capitalize(files[i]->guild_name()),
	files[i]->guild_max_level(),
	files[i]->get_bonuses(files[i]->guild_max_level()));
result += sprintf("Guild Skills:\n");
	for(ii = 0 ; ii < sizeof(index); ii++) {
result += sprintf("%-25s %-2d%%\n", index[ii], skills[index[ii]]);
}
}
resulti=result;
pager = clone_object("/daemons/pager");
pager->move(this_player());
pager->page(resulti);
return 1;
}
