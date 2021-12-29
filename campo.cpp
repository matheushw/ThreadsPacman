#include <string>
#include "campo.hpp"

using namespace std;

class Campo {
    public:
        Campo() {
            campo[0]  = "####################################";
            campo[1]  = "#                ##                #";
            campo[2]  = "# ##### ######## ## ######### #### #";
            campo[3]  = "# ##### ######## ## ######### #### #";
            campo[4]  = "#                                  #";
            campo[5]  = "# ##### # ################# # #### #";
            campo[6]  = "#       #        ###        #      #";
            campo[7]  = "####### ######## ### ######## ######";
            campo[8]  = "xxxxxx# #                   # #xxxxx";
            campo[9]  = "xxxxxx# #                   # #xxxxx";
            campo[10] = "xxxxxx# #  ###############  # #xxxxx";
            campo[11] = "xxxxxx#    ###############    #xxxxx";
            campo[12] = "xxxxxx# #  ###############  # #xxxxx";
            campo[13] = "xxxxxx# #                   # #xxxxx";
            campo[14] = "xxxxxx# #                   # #xxxxx";
            campo[15] = "####### #  ###############  # ######";
            campo[16] = "#                ###               #";
            campo[17] = "# ##### #######  ###  ####### ######";
            campo[18] = "#     #                            #";
            campo[19] = "##### # #  ############### # #######";
            campo[20] = "#       #        ###       #       #";
            campo[21] = "# ############## ### ############# #";
            campo[22] = "#                                  #";
            campo[23] = "####################################";
        }
    private:
        string campo[LINES];
};