#define RACE_D "/daemons/race_stats"

cmd_testraces() {
string *files;
int i;
files = RACE_D->query_races();
printf("+-------------+\n");
printf("| %-2d races    |\n", sizeof(files));
printf("+-------------------------------------------------------------------------+\n");
printf("| Name        | Str | Dex | Con | Wis | Int | Hpr | Spr | Size| skc | spc |\n");
printf("+-------------------------------------------------------------------------+\n");
for ( i = 0 ; i < sizeof(files); i++) {
        printf("| %-11s | %-3d | %-3d | %-3d | %-3d | %-3d | %-3d | %-3d | %-3d | %-3d | %-3d |\n",
        files[i],
        RACE_D->query_race_stat(files[i],"str"),
        RACE_D->query_race_stat(files[i],"dex"),
        RACE_D->query_race_stat(files[i],"con"),
        RACE_D->query_race_stat(files[i],"wis"),
        RACE_D->query_race_stat(files[i],"int"),
        RACE_D->query_race_stat(files[i],"hpr"),
        RACE_D->query_race_stat(files[i],"spr"),
        RACE_D->query_race_stat(files[i],"size"),
        RACE_D->query_race_stat(files[i],"skill_cost"),
        RACE_D->query_race_stat(files[i],"spell_cost"));
}
printf("+-------------------------------------------------------------------------+\n");
return 1;
}
