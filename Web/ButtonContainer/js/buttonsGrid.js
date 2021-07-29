let container = document.querySelectorAll('.ButtonContainer button');
let mapClock = [1, 2, 3, 6, 9, 8, 7, 4, 5];

let arrClock = new Array();
for (let i = 0; i < mapClock.length; i++) 
{
    arrClock[i] = mapClock[i];
}
function clockWise()
{
    let temp = new Array();

    for (let i = 0; i < container.length; i++)
    {
        temp[i] = arrClock[i];
    }
    for (let i = 0; i < container.length - 1; i++)
    {
        if (i === 0)
        {
            arrClock[i] = temp[container.length - 2];
        }
        else
        {
            arrClock[i]= temp[i-1];
        }
        console.log('shift',arrClock[i]);
        container[mapClock[i]-1].textContent = arrClock[i];
    }
}
container[4].addEventListener('click', clockWise);