#include<cstdio>
int a[1030]={
     1, 11, 20, 22, 33, 44, 55, 66, 77, 88, 99, 1000, 1011, 1022, 1033, 1044, 1055, 1066, 1077, 1088, 1099, 2010, 2021, 2032, 2043, 2054, 2065, 2076, 2087, 2098, 2109, 3001, 3012, 3020, 3034, 3045, 3053, 3067, 3078, 3086, 3119, 4002, 4013, 4024, 4030, 4041, 4056, 4068, 4075, 4089, 4097, 5003, 5014, 5025, 5031, 5040, 5052, 5069, 5096, 5107, 5118, 6004, 6015, 6023, 6036, 6042, 6050, 6061, 6079, 6108, 6117, 7005, 7016, 7027, 7038, 7049, 7051, 7060, 7072, 7083, 7094, 8006, 8028, 8035, 8047, 8059, 8062, 8070, 8081, 8093, 8164, 9026, 9037, 9048, 9063, 9071, 9080, 9092, 9129, 9174, 9185, 10039, 10046, 10057, 10073, 10082, 10090, 10158, 10184, 10191, 10295, 100017, 100029, 100058, 100064, 100085, 100091, 100100, 100112, 100123, 100136, 101007, 101018, 101074, 101095, 101101, 101110, 101122, 101133, 101146, 101159, 102008, 102019, 102084, 102102, 102111, 102120, 102135, 102143, 102156, 102167, 103009, 103103, 103114, 103121, 103130, 103142, 103155, 103166, 103177, 103188, 104104, 104113, 104125, 104131, 104140, 104152, 104168, 104176, 104187, 104199, 105105, 105116, 105124, 105132, 105141, 105150, 105163, 105178, 105189, 105197, 106106, 106115, 106127, 106134, 106148, 106151, 106160, 106172, 106183, 106239, 107126, 107137, 107144, 107153, 107161, 107170, 107182, 107198, 107245, 107269, 108128, 108147, 108154, 108162, 108171, 108180, 108193, 108249, 108265, 108286, 109138, 109157, 109173, 109181, 109190, 109275, 109292, 109379, 109394, 109496, 200139, 200145, 200186, 200192, 200200, 200211, 200223, 200234, 200247, 200258, 201149, 201165, 201194, 201201, 201210, 201222, 201233, 201246, 201257, 201268, 202169, 202175, 202196, 202202, 202213, 202220, 202231, 202244, 202267, 202278, 203179, 203195, 203203, 203212, 203221, 203230, 203248, 203254, 203266, 203277, 204204, 204215, 204226, 204232, 204240, 204251, 204263, 204287, 204298, 204309, 205205, 205214, 205227, 205236, 205241, 205250, 205262, 205273, 205288, 205299, 206206, 206217, 206224, 206235, 206242, 206253, 206260, 206271, 206289, 206308, 207207, 207216, 207225, 207238, 207243, 207252, 207261, 207270, 207284, 207319, 208218, 208229, 208237, 208255, 208264, 208272, 208280, 208291, 208356, 208383, 209228, 209259, 209274, 209281, 209290, 209376, 209382, 209393, 209485, 209497, 300208, 300219, 300256, 300282, 300293, 300300, 300311, 300324, 300335, 300347, 301209, 301276, 301283, 301294, 301301, 301310, 301322, 301337, 301345, 301358, 302279, 302285, 302296, 302302, 302313, 302320, 302331, 302344, 302357, 302368, 303297, 303303, 303312, 303321, 303330, 303346, 303354, 303365, 303378, 303389, 304304, 304315, 304323, 304332, 304340, 304351, 304366, 304377, 304388, 304399, 305305, 305314, 305326, 305333, 305341, 305350, 305362, 305387, 305398, 305429, 306306, 306317, 306325, 306334, 306342, 306353, 306360, 306371, 306418, 306439, 307307, 307316, 307328, 307343, 307352, 307361, 307370, 307384, 307395, 307449, 308327, 308336, 308348, 308355, 308363, 308372, 308380, 308391, 308459, 308464, 309338, 309367, 309373, 309381, 309390, 309469, 309474, 309486, 309492, 309575, 400318, 400329, 400364, 400375, 400386, 400392, 400400, 400411, 400423, 400437, 401339, 401374, 401385, 401396, 401401, 401410, 401422, 401433, 401447, 401458, 402349, 402397, 402402, 402413, 402420, 402431, 402444, 402455, 402466, 402478, 403359, 403403, 403412, 403421, 403430, 403445, 403454, 403467, 403476, 403488, 404369, 404404, 404415, 404426, 404432, 404440, 404451, 404463, 404477, 404498, 405405, 405414, 405427, 405436, 405441, 405450, 405462, 405473, 405489, 405508, 406406, 406417, 406424, 406435, 406442, 406453, 406460, 406471, 406499, 406528, 407407, 407416, 407425, 407434, 407443, 407452, 407461, 407470, 407509, 407538, 408419, 408446, 408457, 408465, 408472, 408480, 408491, 408548, 408583, 408594, 409456, 409468, 409479, 409481, 409490, 409582, 409593, 409684, 409695, 409787, 500408, 500475, 500482, 500493, 500500, 500511, 500524, 500536, 500547, 500559, 501409, 501428, 501483, 501494, 501501, 501510, 501522, 501535, 501546, 501557, 502438, 502484, 502495, 502502, 502513, 502520, 502531, 502549, 502556, 502567, 503448, 503487, 503503, 503512, 503521, 503530, 503544, 503555, 503566, 503579, 504504, 504515, 504523, 504532, 504540, 504551, 504568, 504576, 504589, 504597, 505505, 505514, 505526, 505533, 505541, 505550, 505562, 505577, 505588, 505599, 506506, 506517, 506525, 506534, 506542, 506553, 506560, 506571, 506598, 506619, 507507, 507516, 507529, 507543, 507552, 507561, 507570, 507585, 507618, 507654, 508527, 508539, 508545, 508558, 508563, 508572, 508580, 508591, 508664, 508686, 509537, 509565, 509573, 509581, 509590, 509669, 509674, 509692, 509778, 509796, 600518, 600554, 600569, 600586, 600592, 600600, 600611, 600623, 600635, 600647, 601519, 601564, 601578, 601587, 601595, 601601, 601610, 601622, 601633, 601646, 602574, 602596, 602602, 602613, 602620, 602631, 602645, 602657, 602668, 602679, 603584, 603603, 603612, 603621, 603630, 603648, 603655, 603666, 603677, 603689, 604604, 604615, 604626, 604632, 604640, 604651, 604663, 604688, 604697, 604709, 605605, 605614, 605627, 605636, 605641, 605650, 605662, 605673, 605698, 605729, 606606, 606617, 606624, 606638, 606642, 606653, 606660, 606671, 606685, 606699, 607607, 607616, 607625, 607634, 607643, 607652, 607661, 607670, 607708, 607739, 608628, 608637, 608644, 608656, 608665, 608672, 608680, 608691, 608749, 608783, 609658, 609667, 609675, 609681, 609690, 609759, 609776, 609782, 609793, 609894, 700608, 700629, 700676, 700682, 700693, 700700, 700711, 700724, 700735, 700747, 701609, 701678, 701683, 701694, 701701, 701710, 701722, 701736, 701745, 701757, 702639, 702687, 702696, 702702, 702713, 702720, 702731, 702744, 702755, 702768, 703649, 703703, 703712, 703721, 703730, 703746, 703754, 703765, 703777, 703788, 704659, 704704, 704715, 704723, 704732, 704740, 704751, 704766, 704797, 704818, 705705, 705714, 705726, 705733, 705741, 705750, 705762, 705779, 705798, 705807, 706706, 706717, 706725, 706734, 706742, 706753, 706760, 706771, 706789, 706828, 707716, 707727, 707738, 707743, 707752, 707761, 707770, 707784, 707795, 707819, 708737, 708748, 708756, 708763, 708772, 708780, 708791, 708864, 708875, 708899, 709758, 709767, 709773, 709781, 709790, 709869, 709874, 709885, 709892, 709986, 800707, 800718, 800764, 800775, 800786, 800792, 800800, 800811, 800823, 800839, 801719, 801728, 801774, 801785, 801801, 801810, 801822, 801833, 801846, 801857, 802769, 802794, 802802, 802813, 802820, 802831, 802845, 802856, 802867, 802878, 803799, 803803, 803812, 803821, 803830, 803844, 803855, 803866, 803877, 803888, 804804, 804815, 804826, 804832, 804840, 804851, 804863, 804879, 804887, 804898, 805805, 805814, 805827, 805836, 805841, 805850, 805862, 805873, 805889, 805908, 806806, 806817, 806824, 806835, 806842, 806853, 806860, 806871, 806909, 806938, 807816, 807825, 807834, 807843, 807852, 807861, 807870, 807897, 807929, 807948, 808837, 808849, 808854, 808865, 808872, 808880, 808891, 808958, 808976, 808983, 809847, 809859, 809868, 809881, 809890, 809982, 809993, 810884, 810895, 810996, 900808, 900829, 900876, 900882, 900893, 900900, 900911, 900924, 900935, 900947, 901809, 901838, 901883, 901896, 901901, 901910, 901922, 901934, 901945, 901957, 902848, 902886, 902902, 902913, 902920, 902931, 902944, 902955, 902967, 902979, 903858, 903903, 903912, 903921, 903930, 903946, 903954, 903965, 903977, 903989, 904904, 904915, 904923, 904932, 904940, 904951, 904966, 904978, 904987, 904999, 905905, 905914, 905926, 905933, 905941, 905950, 905962, 905988, 905997, 906906, 906917, 906925, 906939, 906942, 906953, 906960, 906971, 906984, 906998, 907907, 907916, 907928, 907943, 907952, 907961, 907970, 907985, 907994, 908918, 908927, 908936, 908949, 908963, 908972, 908980, 908991, 909919, 909937, 909956, 909964, 909973, 909981, 909990, 910959, 910968, 910974, 910992, 911969, 911975, 912995
};
int binary(int l,int r,int k){
    while(r>=l){
        int mid=(l+r)>>1;
        if(a[mid]==k) return 1;
        if(a[mid]>k){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return 0;
}
int main(){
    char str[10];
    while(~scanf("%s",str)){
        if(str[0]=='0'){
            puts("Yes");
        }
        else{
            int tsum=0;
            for(int i=0;str[i];i++){
                tsum*=10;tsum+=str[i]-'0';
            }
            int ans=binary(0,1010,tsum);
            if(!ans) puts("Yes");else puts("No");
        }
    }

    return 0;
}