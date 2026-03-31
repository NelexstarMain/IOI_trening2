#include <bits/stdc++.h>

using namespace std;
// ... (pozostałe deklaracje i makra)

std::unordered_map<std::string, int> time_zone_offsets_minutes = {
    {"UTC", 0},
    {"GMT", 0},
    {"WET", 0},
    {"BST", 60},
    {"IST", 60},
    {"WEST", 60},
    {"CET", 60},
    {"CEST", 120},
    {"EET", 120},
    {"EEST", 180},
    {"MSK", 180},
    {"MSD", 240},
    {"AWST", 480},
    {"AEST", 600},
    {"AEDT", 660},
    {"ACST", 570},
    {"ACDT", 630},
    {"ADT", -180},
    {"AST", -240},
    {"EDT", -240},
    {"EST", -300},
    {"CDT", -300},
    {"CST", -360},
    {"MDT", -360},
    {"MST", -420},
    {"PDT", -420},
    {"PST", -480},
    {"AKDT", -480},
    {"AKST", -540},
    {"HST", -600},
    {"NST", -210},
    {"NDT", -150}
};

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}


int time_to_m(std::string s, char& d) {
    int m, h; 
    
    if (s == "noon") {
        return 720;
    } else if (s == "midnight") {
        return 0; 
    } else if (s.size() == 4) { 
        h = s[0]-'0';
        m = (s[2]-'0')*10 + s[3]-'0';
    } else { 
        h = (s[0]-'0')*10 + s[1]-'0';
        m = (s[3]-'0')*10 + s[4]-'0';
    }

    int h24 = h; 
    if (d == 'a') {
        if (h == 12) {
            h24 = 0; 
        }
    } else if (d == 'p') {
        if (h != 12) {
            h24 += 12; 
        }
    }
    
    return 60 * h24 + m; 
}

int time_to_m(std::string s) {
    char dummy = ' '; 
    return time_to_m(s, dummy);
}

void solve() {
    std::string a = "", b = "", s = "", e = ""; std::cin >> a;
    int timecur;
    
    if (a == "noon" || a == "midnight") {
        std::cin >> s >> e;
        timecur = time_to_m(a);
    } else {
        std::cin >> b >> s >> e;
        timecur = time_to_m(a, b[0]);
    }
    
    int time0 = timecur - time_zone_offsets_minutes[s];
    time0 = (time0 % (24 * 60) + (24 * 60)) % (24 * 60);
    int time1 = time0 + time_zone_offsets_minutes[e];
    time1 = (time1 % (24 * 60) + (24 * 60)) % (24 * 60);
    
    if (time1 == 0) { 
        std::cout << "midnight\n";
    } else if (time1 == 720) { 
        std::cout << "noon\n";
    } else if (time1 > 720) { 
        time1 -= 720; 
        int h = time1 / 60;
        int m = time1 % 60;
        std::cout << ((h == 0) ? 12 : h) << ":" << ((m < 10) ? "0" : "") << m << " p.m.\n";
    } else {
        int h = time1 / 60;
        int m = time1 % 60;
        std::cout << ((h == 0) ? 12 : h) << ":" << ((m < 10) ? "0" : "") << m << " a.m.\n";
    }
}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}