window.onload = () => {
  Vue.createApp({
    data() {
      return {
        msg: "Hello",
        
        
        pointers: {
          cur: 0,
          list: []
        },
        pos: 1717565533,
        step: 1,
        steps: 0,
        
        typeSize: {
          char: 1,
          short: 2,
          int: 4,
          double: 8,
        },
        checkedType: 'char',
        
        vars: {
          list: [],
          char: {
            name: 'c',
            num: 0,
          },
          int: {
            name: 'n',
            num: 0
          },
          short: {
            name: 't',
            num: 0
          },
          double: {
            name: 'd',
            num: 0
          },
          arr: {
            name: 'ar',
            num: 0
          },
          struct: {
            name: 'st',
            num: 0
          },
          pointer: {
            name: 'p',
            num: 0
          }
        },
        color: {
          index: 0,
          change: true,
          colors: [
            'antiquewhite',
            'aqua',
            'bisque',
            'burlywood',
            'cornflowerblue'
          ]
        },
        
        struct: {
          index: 0,
          fields: []
        },
        
        arr: {
          dim: 1,
          dim1: 5,
          dim2: {
            row: 3,
            col: 3
          }
        }
      }
      
    },
    created() {
      for (let i = 50; i >= 0; i--) {
        this.pointers.cur = 1717565532 - i
        this.pointers.list.push({
          id: '0X' + this.pointers.cur.toString(16).toUpperCase(),
          color: null,
        })
      }
    },
    methods: {
      handleMove(dr) {
        this.color.change = false
        if(dr == 'add') {
          this.pos += this.typeSize[this.checkedType] * this.step
        } else if (dr == 'minus') {
          this.pos -= this.typeSize[this.checkedType] * this.step
        }
      },
      handleOpration(op) {
        switch (op){
          case 'var':
            this.pos -= this.typeSize[this.checkedType]
            this.vars.list.push({
              type: this.checkedType,
              name: this.vars[this.checkedType]['name'] + this.vars[this.checkedType]['num']++,
              addr: this.posHexStr
            })
            break;
          case 'pointer':
            this.pos -= this.typeSizeAll['pointer']
            this.vars.list.push({
              type: this.checkedType + '*',
              name: this.vars['pointer']['name'] + this.vars[this.checkedType]['num']++,
              addr: this.posHexStr
            })
            break
          case 'struct':
            this.pos -= this.structSize
            this.vars.list.push({
              type: 'struct S',
              name: this.vars['struct']['name'] + this.vars['struct']['num']++,
              addr: this.posHexStr
            })
            break
          case 'arr':
            this.pos -= this.arrSize
            const name = this.arr.dim == 1 ? `${this.vars['arr']['name']}${this.vars['arr']['num']++}[${this.arr.dim1}]`
              : `${this.vars['arr']['name']}${this.vars['arr']['num']++}[${this.arr.dim2.row}][${this.arr.dim2.col}]`
            this.vars.list.push({
              type: this.checkedType,
              name: name,
              addr: this.posHexStr
            })
            break
          default:
            break;
        }
        
        this.color.change = true
        this.$refs.code.removeAttribute('data-highlighted')
        this.$nextTick(hljs.highlightAll)
      },
      
      handleStructAdd() {
        this.struct.fields.push({
          type: this.checkedType,
          name: 'f' + this.struct.index++
        })
      },
      
      handleStructDel(idx) {
        this.struct.fields.splice(idx, 1)
      }
    },
    computed: {
      posHexStr() {
        return '0X' + this.pos.toString(16).toUpperCase()
      },
      code() {
        let structStr = this.struct.fields.reduce((acc, cur) => {
          return acc + ` ${cur.type} ${cur.name};
          `
        }, ``)
        let cstr = `
        struct S
        {
          ${structStr}
        };
        `
        
        this.vars.list.forEach(item => {
          cstr += `
          ${item.type} ${item.name};`
        })
        return cstr
      },
      
      typeSizeAll() {
        return {
          ...this.typeSize,
          pointer: 8
        }
      },
      structSize() {
        return this.struct.fields.reduce((accumulator, currentValue) => {
          console.log(accumulator, currentValue)
          return accumulator + this.typeSizeAll[currentValue.type]
        }, 0);
      },
      arrSize() {
        if(this.arr.dim == 1) {
          return parseInt(this.arr.dim1) * this.typeSize[this.checkedType]
        } else {
          return parseInt(this.arr.dim2.col * this.arr.dim2.row) * this.typeSize[this.checkedType]
        }
      }
      
    },
    
    watch: {
      pos(val, oldVal) {
        if (this.color.change) {
          const coloraddrs = []
          for (let i = val; i < oldVal; i++) {
            coloraddrs.push('0X' + i.toString(16).toUpperCase())
          }
          const tocolor = this.pointers.list.filter((item) => coloraddrs.includes(item.id))
          tocolor.forEach((item) => {
            
            item.color = this.color.colors[this.color.index]
              
          })
          this.color.index = (this.color.index + 1) % this.color.colors.length
        }
        
        this.steps = Math.abs(val - oldVal)
        
      },
      code() {
        this.$refs.code.removeAttribute('data-highlighted')
        this.$nextTick(hljs.highlightAll)
      }
    }
  }).mount("#app")
  
  hljs.highlightAll();
}