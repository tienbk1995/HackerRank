const btn0 = document.getElementById('btn0');
const btn1 = document.getElementById('btn1');
const btnClr = document.getElementById('btnClr');
const btnEql = document.getElementById('btnEql');
const btnSum = document.getElementById('btnSum');
const btnSub = document.getElementById('btnSub');
const btnMul = document.getElementById('btnMul');
const btnDiv = document.getElementById('btnDiv');
// Result table
const res = document.getElementById('res');

function setButtonText(e)
{
    res.innerHTML += e.target.innerHTML;
}

function clearText(e)
{
    res.innerHTML ='';
}

function calculation(e)
{
    let newResult = 0;
    let currText = res.innerHTML;
    let operatorRegEx = /[+\-*\/]/;
    let operand1RegEx = /(\d+)[+\-*\/]/;
    let operand2RegEx = /^.*[+\-*\/](\d+)/;
    let operator = currText.match(operatorRegEx);
    let operand1 = currText.match(operand1RegEx);
    let operand2 = currText.match(operand2RegEx);
    operand1 = parseInt(operand1[1], 2);
    operand2 = parseInt(operand2[1], 2);
    switch (operator[0])
    {
        case '+': 
            newResult = operand1 + operand2; 
            break;
        case '-': 
            newResult = operand1 - operand2; 
            break;
        case '*': 
            newResult = operand1 * operand2; 
            break;
        case '/': 
            newResult = Math.floor(operand1 / operand2); 
            break;
        default: 
            console.log('exception'); 
            break;
    }
    newResult = (newResult >>> 0).toString(2);
    res.innerHTML = newResult;
}
btn0.addEventListener('click',setButtonText);
btn1.addEventListener('click',setButtonText);
btnSum.addEventListener('click',setButtonText);
btnSub.addEventListener('click',setButtonText);
btnMul.addEventListener('click',setButtonText);
btnDiv.addEventListener('click',setButtonText);
btnClr.addEventListener('click', clearText);
btnEql.addEventListener('click', calculation);