<template>
    <div>
    <b-container fluid='sm'>
    <!-- <b-row align-v='center'> -->
    <b-card
        bg-variant="dark"
        text-variant="white"
        title="Local"
        style="max-width: 80rem;"
        align="center"
        >
        <b-card-text>
        Date: {{times.local.date}}
        Time: {{times.local.time}}
        </b-card-text>
    </b-card>

    <b-card
        bg-variant="dark"
        text-variant="white"
        title="UTC"
        style="max-width: 80rem;"
        align="center">
        <b-card-text>
        Date: {{times.utc.date}}
        Time: {{times.utc.time}}
        </b-card-text>
    </b-card>
    <!-- </b-row> -->
    </b-container>

    </div>
</template>

<script>
// @ is an alias to /src

// import todoCard from '@/components/todoCard.vue';
import axios from 'axios';
export default {
  name: 'Ex4',
  components: {
    // 'todo-card': todoCard
  },
  data(){
    return {
        times: ''
    }
  },
  async created(){
    try{
      const response = await axios.get('http://localhost:5000/Ex5/');
      this.times = response.data;
    } catch(e){
      console.error(e);
      console.log("Error");
    }
  },
}   
</script>