let string = "youtube";
let a = document.links;
Array.from(a).forEach(function (elements) {
    if (elements.toString().includes(string)) {
        document.body.innerHTML = elements;
        console.log(`<h2>{elements}</h2>`);
    }
});
const flname = `<h1> ${"Aneeq Khurram"} </h1>`;
string = `<h2>${string}</h2>`;
document.body.innerHTML = `<h2>Aneeq Khurram</h2>`;
;

// element = element.className;
// element = element.childNodes;
// element = element.parentNode;
// element.style.color = 'red';
// element.innerText = 'Harry is a good boy';
// element.innerHTML = '<b>Harry is a good boy</b>';
// console.log(element.innerText);console.log('Welcome to tutorial 14');
/*
element selectors:
1. Single element selector
2. Multi element selector
*/

// 1. Single element selector
let element = document.getElementById('myfirst');
// element = element.className;
// element = element.childNodes;
// element = element.parentNode;
// element.style.color = 'red';
// element.innerText = 'Harry is a good boy';
// element.innerHTML = '<b>Harry is a good boy</b>';
// console.log(element.innerText);


let sel = document.querySelector('#myfirst');
sel = document.querySelector('.child');
sel = document.querySelector('div');
// sel.style.color = 'green';
console.log(sel)

// 2. Multi element selector
let elems = document.getElementsByClassName('child');
elems = document.getElementsByClassName('container');
elems = document.getElementsByTagName('div');
console.log(elems)

for (let index = 0; index < elems.length; index++) {
    const element = elems[index];
    console.log(element);
    element.style.color = 'blue';
}
// Array.from(elems).forEach(element => {
//     console.log(element);
//    element.style.color = 'blue';
// });
// console.log(elems[0].getElementsByClassName('child'))