const textArea = document.getElementById('#text_area')
const generate = document.getElementById('#generate')
const copy = document.getElementById('#copy')

const characters = ' !"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~';

generate.addEventListener('click', () => {
    textArea.innerHTML = ''
    for(let i = 0; i < 17; i++) {
        let index = Math.round((Math.random() * 100) % 94)
        textArea.innerText += characters[index]
    }
})

copy.addEventListener('click', () => {
    if(textArea.innerText == 'Click "Generate" to generate a random password') {
        alert(textArea.innerText)
    } else {
        navigator.clipboard.writeText(textArea.innerText)
    }
})