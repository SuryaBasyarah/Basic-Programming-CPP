#include <iostream>
#include <cmath>
using namespace std;

const float pi = 3.14;



typedef struct
{
    int degrees;
    int minutes;
    char direction;

}long_lat_t;

typedef struct location_s
{
    char place[20];
    long_lat_t longitude, latitude;
    struct location_s *linkp;

}location_t;
location_t *Lokasi_Hotel, *prevp, *newp;
void jarak()
{
    location_t Lokasi_Hotel[2];
    int dlong, dlat;

    dlong = abs(Lokasi_Hotel[1].longitude.degrees-Lokasi_Hotel[0].longitude.degrees);
    dlat = abs(Lokasi_Hotel[1].latitude.degrees-Lokasi_Hotel[0].latitude.degrees);

    float ans = pow(sin(dlat / 2), 2) + cos(Lokasi_Hotel[1].latitude.degrees) * cos(Lokasi_Hotel[0].latitude.degrees)
    * pow(sin(dlong / 2), 2);

    ans = 2 * asin(sqrt(ans));
    int R = 6371;
    ans = ans * R;

    cout << "jarak: " << ans;

    
}

void convert()
{
    float radius;
    while ((*Lokasi_Hotel).linkp != NULL)
    {
        radius = (*Lokasi_Hotel).longitude.degrees * pi / 180;
        cout << radius;
    }
}

void userinput()
{
    Lokasi_Hotel = new location_t;
    cin >> (*Lokasi_Hotel).place;
    prevp = Lokasi_Hotel;
    while (true)
    {
        newp = new location_t;
        cout << "Nama Hotel: ";
        cin >> (*newp).place;
        if ((*newp).place == "stop")
        {
            break;
        }
        cout << "Longitude degrees: ";
        cin >> (*newp).longitude.degrees;
        cout << "Longitude minutes: ";
        cin >> (*newp).longitude.minutes;
        cout << "Longitude direction: ";
        cin >> (*newp).longitude.direction;
        cout << endl;

        cout << "latitude degrees: ";
        cin >> (*newp).latitude.degrees;
        cout << "latitude minutes: ";
        cin >> (*newp).latitude.minutes;
        cout << "latitude direction: ";
        cin >> (*newp).latitude.direction;
        (*prevp).linkp = newp;
        prevp = newp;

    }
    (*prevp).linkp = NULL;
}

void showall(location_t *headp)
{
    while (headp != NULL)
    {
        cout << (*Lokasi_Hotel).place << endl;
    }
}

int main()
{

    userinput();
    
    jarak();
    convert();
    showall(Lokasi_Hotel);

    return 0;
}