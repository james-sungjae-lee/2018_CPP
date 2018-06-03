#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

int main() {
    ifstream in;
    in.open("input.txt");

    int a = 0;

    in >> a;

    for (int i = 0; i < a; i++) {

        int x=0;
        int y=0;

        in >> x >> y;

        // 2차원 배열 동적할당
        char **arr = new char*[x];

        for(int i=0; i<x; ++i){
            arr[i] = new char[y];
            memset(arr[i], 0, sizeof(char)*y);
        }

        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                in >> arr[i][j];
            }
        }

        int cas=0;
        in >> cas; // 체크 할 단어 갯수

        int xx=0;
        int yy=0;
        int path=8;

        for(int i=0; i<cas; i++){
            path=8;
            char word[205]={0x00, };
            in >> word;
            int k=0;
            k= strlen(word);

            // path 7
            for(int m=x-1; m>k-2; m--){
                for(int l=y-1; l>k-2; l--){
                    for(int j=0; j<k; j++){
                        if(arr[m-j][l-j]==word[j]){
                            path=7;
                            xx=m;
                            yy=l;
                            continue;
                        }
                        else{
                            path=8;
                            break;
                        }
                    }
                    if(path!=8)
                        break;
                }
                if(path!=8)
                    break;
            }
            if(path!=8){
                cout << xx+1 << " " << yy+1 << " " << path << endl;
                continue;
            }

            // path 4
            for(int m=0; m<x-k+1; m++){
                for(int l=0; l<y; l++){
                    for(int j=0; j<k; j++){
                        if(arr[m+j][l]==word[j]){
                            path=4;
                            xx=m;
                            yy=l;
                            continue;
                        }
                        else{
                            path=8;
                            break;
                        }
                    }
                    if(path!=8)
                        break;
                }
                if(path!=8)
                    break;
            }
            if(path!=8){
                cout << xx+1 << " " << yy+1 << " " << path << endl;
                continue;
            }

            // path 0
            for(int m=x-1; m>k-2; m--){
                for(int l=0; l<y; l++){
                    for(int j=0; j<k; j++){
                        if(arr[m-j][l]==word[j]){
                            path=0;
                            xx=m;
                            yy=l;
                            continue;
                        }
                        else{
                            path=8;
                            break;
                        }
                    }
                    if(path!=8)
                        break;
                }
                if(path!=8)
                    break;
            }
            if(path!=8){
                cout << xx+1 << " " << yy+1 << " " << path << endl;
                continue;
            }

            // path 1
            for(int m=x-1; m>k-2; m--){
                for(int l=0; l<y-k+1; l++){
                    for(int j=0; j<k; j++){
                        if(arr[m-j][l+j]==word[j]){
                            path=1;
                            xx=m;
                            yy=l;
                            continue;
                        }
                        else{
                            path=8;
                            break;
                        }
                    }
                    if(path!=8)
                        break;
                }
                if(path!=8)
                    break;
            }
            if(path!=8){
                cout << xx+1 << " " << yy+1 << " " << path << endl;
                continue;
            }

            // path 5
            for(int m=0; m<x-k+1; m++){
                for(int l=y-1; l>k-2; l--){
                    for(int j=0; j<k; j++){
                        if(arr[m+j][l-j]==word[j]){
                            path=5;
                            xx=m;
                            yy=l;
                            continue;
                        }
                        else{
                            path=8;
                            break;
                        }
                    }
                    if(path!=8)
                        break;
                }
                if(path!=8)
                    break;
            }
            if(path!=8){
                cout << xx+1 << " " << yy+1 << " " << path << endl;
                continue;
            }

            // path 2
            for(int m=0; m<x; m++){
                for(int l=0; l<y-k+1; l++){
                    for(int j=0; j<k; j++){
                        if(arr[m][l+j]==word[j]){
                            path=2;
                            xx=m;
                            yy=l;
                            continue;
                        }
                        else{
                            path=8;
                            break;
                        }
                    }
                    if(path!=8)
                        break;
                }
                if(path!=8)
                    break;
            }
            if(path!=8){
                cout << xx+1 << " " << yy+1 << " " << path << endl;
                continue;
            }

            // path 6
            for(int m=0; m<x; m++){
                for(int l=y-1; l>k-2; l--){
                    for(int j=0; j<k; j++){
                        if(arr[m][l-j]==word[j]){
                            path=6;
                            xx=m;
                            yy=l;
                            continue;
                        }
                        else{
                            path=8;
                            break;
                        }
                    }
                    if(path!=8)
                        break;
                }
                if(path!=8)
                    break;
            }
            if(path!=8){
                cout << xx+1 << " " << yy+1 << " " << path << endl;
                continue;
            }

            // path 3
            for(int m=0; m<x-k+1; m++){
                for(int l=0; l<y-k+1; l++){
                    for(int j=0; j<k; j++){
                        if(arr[m+j][l+j]==word[j]){
                            path=3;
                            xx=m;
                            yy=l;
                            continue;
                        }
                        else{
                            path=8;
                            break;
                        }
                    }
                    if(path!=8)
                        break;
                }
                if(path!=8)
                    break;
            }
            if(path!=8){
                cout << xx+1 << " " << yy+1 << " " << path << endl;
                continue;
            }

            if(path==8)
                cout << -1 << endl;

        }
    }
}
