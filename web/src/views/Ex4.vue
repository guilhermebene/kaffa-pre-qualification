<template>
    <div>
         <b-container fluid='sm'>
           <b-col><b-button size="lg" variant="outline-primary" @click="toggleNewCard">Create TO-DO</b-button></b-col>
          <b-card
        style="max-width: 80rem;"
        align="center" v-if="new_card">
        <b-form-textarea
        id="textarea"
        v-model="new_todo.content"
        placeholder="Enter new TO-DO"
        rows="3"
        max-rows="6"
        ></b-form-textarea>

    <b-button variant="primary" @click="onCreateTODO">Create TO-DO</b-button>
        </b-card>
    <b-col align-v='center'>
          <b-card
        :title="'TO-DO #' + index"
        style="max-width: 80rem;"
        align="center" v-for="(todo,index) in todos" :key="todo.id">
        <b-card-text>
        {{todo.content}}
        </b-card-text>

        <b-button variant="primary" @click="onClickDelete(todo)">Delete</b-button>
    </b-card>
    </b-col>
    </b-container>

    </div>
</template>

<script>

import axios from 'axios';
export default {
  name: 'Ex4',
  components: {
    // 'todo-card': todoCard
  },
  data(){
    return {
      todos: [],
      new_card: false,
      new_card_text: '',
      new_todo: {
        'content': ''
      }
    }
  },
  async created(){
    this.getTodos();
  },
  methods: {
      async getTodos(){
        try{
          const response = await axios.get('http://localhost:5000/Ex4/todo/all');
          this.todos = response.data.data;
        } catch(e){
          console.error(e);
        }
    },
      async onClickDelete(todo){
          console.log(todo);
          try{
            await axios.post('http://localhost:5000/Ex4/todo/delete', todo);
            this.getTodos();
          } catch(e){
            console.error(e);
          }
      },
      toggleNewCard(){
        this.new_card = !this.new_card;
        // console.log(this.new_card);
      },
      async onCreateTODO(){
        console.log(this.new_todo);
        try{
          await axios.post('http://localhost:5000/Ex4/todo/new', JSON.stringify(this.new_todo), {
          headers: {
            'Content-Type': 'application/json',
            }
          });
          this.new_card = false;
          this.getTodos();
        } catch(e){
            console.error(e);
          }       
      }
  },
}   
</script>